# 1484. Group Sold Products By The Date

import pandas as pd

# Solution 1 in bad python fashion using groupby, count, rename, join and sort_values functions

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    activities = activities.drop_duplicates()
    df = activities.groupby(by=['sell_date']).count().reset_index()
    df.rename(columns = {'product':'num_sold'}, inplace = True)
    temp = []
    for ind in df.index:
        lst = activities.loc[activities['sell_date'] == df.loc[ind]['sell_date']]['product'].tolist()
        lst.sort()
        temp.append(",".join([str(x) for x in lst]))
    df['products'] = temp
    df.sort_values('sell_date', inplace=True)
    return df

# Solution 2 using groupby, agg, nunqiue, join and sort_values functions
def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    return activities.groupby('sell_date')['product'].agg([('num_sold', 'nunique'),('products', lambda x: ','.join(sorted(x.unique())))]).reset_index()