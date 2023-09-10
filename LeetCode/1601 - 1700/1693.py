# 1693. Daily Leads and Partners

import pandas as pd    

# Solution 1 using groupby and nunique
def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    df =  daily_sales.groupby(by=['date_id', 'make_name']).nunique().reset_index()
    df.columns = ['date_id', 'make_name', 'unique_leads', 'unique_partners']
    return df

# Solution 2 oneliner using groupby and agg
def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    return daily_sales.groupby(by=['date_id', 'make_name']).agg({'lead_id': 'nunique', 'partner_id': 'nunique'}).reset_index().rename(columns={'lead_id': 'unique_leads', 'partner_id': 'unique_partners'})
