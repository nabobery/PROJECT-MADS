# 595. Big Countries

import pandas as pd

#  solution 1 
def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world.loc[(world["population"] >= 25000000) | (world["area"] >= 3000000), ["name", "population", "area"]]

# solution 1 but 2 liner
def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
    return df[['name', 'population', 'area']]

# solution 2
def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world.loc[world.eval('population >= 25000000 | area >= 3000000'), ["name", "population", "area"]]

