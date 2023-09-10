# 511. Game Play Analysis I

import pandas as pd

# Solution 1 using groupby and agg
def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return activity.groupby(['player_id']).agg(player_id = ('player_id', 'first'),first_login = ('event_date','min'))

# Solution 1 but using groupby and agg but without assigning player_id
def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return activity.groupby(['player_id']).agg(first_login = ('event_date','min')).reset_index()

# Solution 2 using groupby and min and renaming columns
def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return activity.groupby(['player_id']).min().rename(columns={'event_date':'first_login'}).reset_index()[['player_id','first_login']]