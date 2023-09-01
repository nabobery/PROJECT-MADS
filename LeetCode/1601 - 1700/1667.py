# 1667. Fix Names in a Table

import pandas as pd

# Solution 1 using capitalize()
def fix_names(users: pd.DataFrame) -> pd.DataFrame:
        users['name'] = users['name'].str.capitalize()
        return users.sort_values(by=['user_id'])

# Solution 2 without using capitalize() and iterating through the rows
def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    for i in range(len(users)):
        users.loc[i, 'name'] = users.loc[i, 'name'][0].upper() + users.loc[i, 'name'][1:].lower()
    return users.sort_values(by=['user_id'])
    