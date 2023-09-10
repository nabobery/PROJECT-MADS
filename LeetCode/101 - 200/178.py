# 178. Rank Scores

import pandas as pd

# # Solution 1 using sort_values, reset_index, iterating and .at() method
def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores = scores.sort_values(by='score', ascending=False)
    rank = 1
    scores['rank'] = [rank ]* len(scores.index)
    scores = scores.reset_index(drop = True)
    for ind in range(1, len(scores.index)):
        if(scores.loc[ind]['score'] == scores.loc[ind-1]['score']):
            scores.at[ind, 'rank'] = rank
        else:
            rank += 1
            scores.at[ind, 'rank'] = rank
    return scores.loc[:, ['score', 'rank']]

# Solution 2  using rank method
def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores = scores.sort_values(by='score', ascending=False)
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    return scores.loc[:,['score', 'rank']]
    