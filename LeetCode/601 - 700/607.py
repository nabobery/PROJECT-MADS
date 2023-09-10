# 607. Sales Person

import pandas as pd

# Solution 1 using condition and isin
def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    ind = company[company.name == "RED"]['com_id']
    s = orders[orders.com_id.isin(ind)]['sales_id']
    return sales_person[~sales_person.sales_id.isin(s)][['name']]

# Solution 1 one liner
def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return sales_person[~sales_person.sales_id.isin(orders[orders.com_id.isin(company[company.name == "RED"]['com_id'])]['sales_id'])][['name']]

# Solution 2 using merge
def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return sales_person[~sales_person.sales_id.isin(orders.merge(company[company.name == "RED"], on='com_id')['sales_id'])][['name']]