# 1683. Invalid Tweets

import pandas as pd

# Solution 1
def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
   return tweets.loc[tweets['content'].str.len() > 15, ["tweet_id"]]

# Solution 2 using eval
def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets.loc[tweets.eval('content.str.len() > 15'), ["tweet_id"]]

# Solution 3 using query
def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets.query('content.str.len() > 15')[["tweet_id"]]

# Solution 4 using apply
def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets[tweets['content'].apply(lambda x: len(x) > 15)][["tweet_id"]]