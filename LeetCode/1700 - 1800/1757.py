# 1757. Recyclable and Low Fat Products
import pandas as pd


# Solution 1
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products.loc[(products["low_fats"] == 'Y') & (products['recyclable'] == 'Y'), ["product_id"]]

# Solution 1 but 2 liner
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')]
    return df[['product_id']]

# Solution 2
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products.loc[products.eval('low_fats == "Y" & recyclable == "Y"'), ["product_id"]]