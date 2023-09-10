# 1378. Replace Employee ID With The Unique Identifier

import pandas as pd

# Solution 1 using left join
def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(employees, employee_uni, on="id", how="left")[['unique_id', 'name']]

# Solution 2 using map
def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({'unique_id': employees['id'].map(employee_uni.set_index('id')['unique_id']), 'name': employees['name']})

