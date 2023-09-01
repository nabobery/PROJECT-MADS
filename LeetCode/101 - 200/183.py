# 183. Customers Who Never Order

import pandas as pd

# Solution 1
def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    result = pd.DataFrame()
    result['Customers'] = customers.loc[~customers["id"].isin(orders["customerId"]), ["name"]]
    return result

# Solution 1 but by renaming the column
def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the rows which `id` is not present in orders['customerId'].
    df = customers[~customers['id'].isin(orders['customerId'])]

    # Build a dataframe that only contains the column `name` 
    # and rename the column `name` as `Customers`.
    df = df[['name']].rename(columns={'name': 'Customers'})
    return df

# Solution 2 using left join
def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Perform left join on the two dataframes on the column `id` and `customerId`
    df = customers.merge(orders, left_on='id', right_on='customerId', how='left')
    # Select the rows which `customerId` is NaN so that we can find the customers who never order.
    df = df[df['customerId'].isna()]
    # Build a dataframe that only contains the column `name` and rename the column `name` as `Customers`.
    df = df[['name']].rename(columns={'name': 'Customers'})
    return df
