# 1148. Article Views I

import pandas as pd

# Solution 1
def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views.loc[(views["author_id"] == views["viewer_id"]), ["author_id"]]
    df = df[['author_id']].rename(columns={'author_id': 'id'})
    df = df.drop_duplicates('id')
    df = df.sort_values(by=['id'])
    return df

# Solution 1 but one liner
def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return views.loc[(views["author_id"] == views["viewer_id"]), ["author_id"]].rename(columns={'author_id': 'id'}).drop_duplicates('id').sort_values(by=['id'])

# Solution 2 wihout using drop_duplicates
def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views.loc[(views["author_id"] == views["viewer_id"]), ["author_id"]]
    df = df[['author_id']].rename(columns={'author_id': 'id'})
    df = df.drop(df[df.duplicated()].index)
    df = df.sort_values('id')
    return df