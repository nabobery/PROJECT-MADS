# 570. Managers with at Least 5 Direct Reports

import pandas as pd
 
# Solution 1 using groupby, count, reset_index, merge, dropna
def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.groupby('managerId').count().reset_index()
    df = df[df.id >= 5]
    df = pd.merge(employee, df, how='right', left_on='id', right_on='managerId').rename(columns = {'name_x' : 'name'})
    df = df.dropna(subset=['name'])
    return df[['name']]

# Solution 2using groupby, agg, query and isin
def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.groupby('managerId').agg(count = ('id', 'count')).query('count >= 5')
    df = employee[employee.id.isin(df.index)]
    return df[['name']]
