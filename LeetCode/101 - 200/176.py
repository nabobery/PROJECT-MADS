# 176. Second Highest Salary

import pandas as pd

# Solution 1: Using unique() and sorted() functions
def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([None], columns = ['SecondHighestSalary'])
    n = len(employee['salary'].unique())
    if(n > 1): df['SecondHighestSalary'] = sorted(employee['salary'].unique())[n-2]
    return df

# Solution 2: Using rank() function
def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([None], columns = ['SecondHighestSalary'])
    employee['rank'] = employee['salary'].rank(method='dense', ascending=False)
    if(len(employee['salary'].unique()) > 1): 
        df['SecondHighestSalary'] = employee[employee['rank'] == 2]['salary'].values
    return df