# 1527. Patients With a Condition

import pandas as pd


# Solution 1 using df.apply()
def helper(condition: str) -> bool:
    list = condition.split(' ')
    for s in list:
        if s.startswith('DIAB1'): return True
    return False

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    mask = patients['conditions'].apply(helper)
    return patients[mask]
    
# Solution 2 using df.str.contains() and regex
def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    mask = patients['conditions'].str.contains(r'\bDIAB1')
    return patients[mask]