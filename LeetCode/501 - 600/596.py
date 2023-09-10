# 596. Classes More Than 5 Students

import pandas as pd

# Solution 1 using groupby, nunique, index.values
def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby('class')['student'].nunique() >= 5
    return pd.DataFrame(df[df].index.values, columns=['class'])

# Solution 2 using groupby, nunique, reset_index, query
def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby('class')['student'].nunique().reset_index()
    return df.query('student >= 5')[['class']]

# Solution 3 using aggregate, reset_index, query
def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby('class').agg({'student': 'nunique'}).reset_index()
    return df.query('student >= 5')[['class']]
