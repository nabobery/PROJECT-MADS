#

import pandas as pd

# Solution 1 gives TLE
def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([], columns=['category', 'accounts_count'])
    count1 = count2 = count3 = 0
    for ind in accounts.index:
        if accounts.loc[ind]['income'] < 20000:
            count1 += 1
        elif accounts.loc[ind]['income'] >= 20000 and accounts.loc[ind]['income'] <= 50000:
            count2 += 1
        else:
            count3 += 1
    df.loc[len(df)] = ['Low Salary', count1]
    df.loc[len(df)] = ['Average Salary', count2]
    df.loc[len(df)] = ['High Salary', count3]
    return df
    
# Solution 2 using len and loc and boolean conditions
def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([], columns=['category', 'accounts_count'])
    df.loc[len(df)] = ['Low Salary', len(accounts.loc[accounts['income'] < 20000])]
    df.loc[len(df)] = ['Average Salary', len(accounts.loc[(accounts['income'] >= 20000) & (accounts['income'] <= 50000)])]
    df.loc[len(df)] = ['High Salary', len(accounts.loc[accounts['income'] > 50000])]
    return df

# Solution 2 one liner
def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame([['Low Salary', len(accounts.loc[accounts['income'] < 20000])],
                         ['Average Salary', len(accounts.loc[(accounts['income'] >= 20000) & (accounts['income'] <= 50000)])],
                         ['High Salary', len(accounts.loc[accounts['income'] > 50000])]],
                        columns=['category', 'accounts_count'])
