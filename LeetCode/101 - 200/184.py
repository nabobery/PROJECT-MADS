# 184. Department Highest Salary

import pandas as pd

# Solution 1 using groupby and max
def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(employee, department, left_on="departmentId" ,right_on="id", how="left")
    df.rename({'name_y' : 'Department', 'name_x' : 'Employee', 'salary' : 'Salary'}, axis=1, inplace=True)
    temp = df.groupby('Department')['Salary'].max()
    indices = []
    for id in df.index:
        if(df.loc[id]['Salary'] == temp[df.loc[id]['Department']]): indices.append(id)
    return df.loc[indices, ['Department', 'Employee', 'Salary']]

# Solution 2 using merge, groupby and apply
def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(employee, department, left_on="departmentId" ,right_on="id", how="left")
    df.rename({'name_y' : 'Department', 'name_x' : 'Employee', 'salary' : 'Salary'}, axis=1, inplace=True)
    return df.groupby('Department').apply(lambda x: x[x['Salary'] == x['Salary'].max()])[['Department', 'Employee', 'Salary']]