# 2356. Number of Unique Subjects Taught by Each Teacher

import pandas as pd

# Solution 1 using nunique, groupby, reset_index and rename
def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    return teacher.groupby(['teacher_id'])['subject_id'].nunique().reset_index().rename(columns={'subject_id':'cnt'})

# Solution 2 using groupby, agg, reset_index and rename
def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    return teacher.groupby(['teacher_id']).agg({'subject_id':'nunique'}).reset_index().rename(columns={'subject_id':'cnt'})
