# 196. Delete Duplicate Emails

import pandas as pd


# Solution 1 using sort_values and drop_duplicates
# Modify Person in place
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    person.sort_values(by=['id'], inplace=True)
    person.drop_duplicates(subset=['email'],inplace=True)



