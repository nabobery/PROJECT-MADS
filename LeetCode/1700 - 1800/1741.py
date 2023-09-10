# 1741. Find Total Time Spent by Each Employee

import pandas as pd


# Solution 1 using groupby, head and sum
def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([], columns=['day', 'emp_id', 'total_time'])
    temp = employees.groupby(['emp_id', 'event_day'])[['out_time', 'in_time']].sum().reset_index()
    df['day'] = temp['event_day']
    df['emp_id'] = temp['emp_id']
    df['total_time'] = temp['out_time'] - temp['in_time']
    return df

# Solution 2 using groupby, agg and sum
def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame([], columns=['day', 'emp_id', 'total_time'])
    temp = employees.groupby(['emp_id', 'event_day']).agg({'out_time': 'sum', 'in_time': 'sum'}).reset_index()
    df['day'] = temp['event_day']
    df['emp_id'] = temp['emp_id']
    df['total_time'] = temp['out_time'] - temp['in_time']
    return df