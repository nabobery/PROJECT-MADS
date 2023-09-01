# 1517. Find Users With Valid E-Mails

import pandas as pd

# Solution 1 using regex
def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    return users.loc[users['mail'].str.match(r'(^[a-zA-Z][\w\-\.]*@leetcode\.com)') == True]
