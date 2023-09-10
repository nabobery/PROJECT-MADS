# 177. Nth Highest Salary

import pandas as pd

# Solution 1: Using unique() and sorted() functions
def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    res = pd.DataFrame()
    res['getNthHighestSalary(' + str(N) +')'] = [pd.NA]
    n = len(employee['salary'].unique())
    if(N <= n): 
        res['getNthHighestSalary(' + str(N) +')'] = [sorted(employee['salary'].unique())[n-N]]
    return res

# Solution 2: Using rank() function
def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    res = pd.DataFrame()
    res['getNthHighestSalary(' + str(N) +')'] = [pd.NA]
    employee['rank'] = employee['salary'].rank(method='dense', ascending=False)
    if(N <= len(employee['salary'].unique())): 
        res['getNthHighestSalary(' + str(N) +')'] = employee[employee['rank'] == N]['salary'].values
    return res