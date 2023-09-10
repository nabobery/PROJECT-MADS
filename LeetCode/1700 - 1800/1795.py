# 1795. Rearrange Products Table

import pandas as pd

# Solution 1 using notnull and append

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([], columns=['product_id','store', 'price'])
    for ind in products.index:
        if pd.notnull(products.loc[ind]['store1']):
            df.loc[len(df)] = [products.loc[ind]['product_id'], 'store1', products.loc[ind]['store1']]
        if  pd.notnull(products.loc[ind]['store2']):
            df.loc[len(df)] = [products.loc[ind]['product_id'], 'store2', products.loc[ind]['store2']]
        if pd.notnull(products.loc[ind]['store3']):
            df.loc[len(df)] = [products.loc[ind]['product_id'], 'store3', products.loc[ind]['store3']]
    return df

# Solution 2 using melt
def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    df = pd.melt(products, id_vars=['product_id'], value_vars=['store1', 'store2', 'store3'], value_name='price')
    df = df.dropna()
    df['store'] = df['variable']
    df = df.drop(columns=['variable'])
    return df

# Solution 3 one line using melt
def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(products, id_vars='product_id', var_name='store', value_name='price').dropna()