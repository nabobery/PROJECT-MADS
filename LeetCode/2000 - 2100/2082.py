# 2082. The Number of Rich Customers

import pandas as pd

# Solution 1 using groupby and max
def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    store['total'] = store.groupby('customer_id')['amount'].max()
    df = pd.DataFrame([len(store[store['total'] > 500])], columns=['rich_count'])
    return df

# Solution 2 using filter using loc and nunique
def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([store.loc[store['amount'] > 500, 'customer_id'].nunique()], columns=['rich_count'])
    return df