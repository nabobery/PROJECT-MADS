# 1873. Calculate Special Bonus

import pandas as pd

# Solution 1 using loc 
def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = 0
    employees.loc[(employees['employee_id']% 2== 1) & (employees['name'].str[0] != 'M'), 'bonus'] = employees['salary']
    df = employees[['employee_id', 'bonus']].sort_values(by='employee_id', ascending=True)
    return df

# Solution 2 using apply
def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(lambda x: x['salary'] if x['employee_id'] % 2 == 1 and x['name'][0] != 'M' else 0, axis=1)
    df = employees[['employee_id', 'bonus']].sort_values(by='employee_id', ascending=True)
    return df