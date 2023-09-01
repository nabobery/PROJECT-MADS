# 1173. Immediate Food Delivery I

import pandas as pd

# Solution 1 using loc, shape and len
def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame()
    df['immediate_percentage'] = [round(100*(delivery.loc[delivery['order_date'] == delivery['customer_pref_delivery_date']].shape[0])/len(delivery),2)]
    return df

# Solution 1 but one liner
def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({'immediate_percentage': [
        round(delivery[delivery['order_date'] == delivery['customer_pref_delivery_date']].size / delivery.size * 100, 2)
    ]})