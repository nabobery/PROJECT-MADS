# 1050. Actors and Directors Who Cooperated At Least Three Times

import pandas as pd

# Solution 1 using groupby, count, reset_index
def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    df = actor_director.groupby(['actor_id', 'director_id']).count().reset_index()
    return df.loc[df['timestamp'] >= 3, ['actor_id', 'director_id']]

# Solution 2 one liner
def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    return actor_director.groupby(['actor_id', 'director_id']).count().reset_index().loc[lambda x: x['timestamp'] >= 3, ['actor_id', 'director_id']]

# Solution 3 using groupby, agg
def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    return actor_director.groupby(['actor_id', 'director_id']).agg({'timestamp': 'count'}).reset_index().loc[lambda x: x['timestamp'] >= 3, ['actor_id', 'director_id']]