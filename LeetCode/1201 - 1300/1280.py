# 1280. Students and Examinations

import pandas as pd

# Solution 1 using cross join, merge, sort, agg, map, fillna, astype
def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    df = students.merge(subjects, how='cross')
    df = df.sort_values(by=['student_id', 'subject_name'])
    s = examinations[['student_id', 'subject_name']].agg(frozenset, axis=1).value_counts()
    df['attended_exams'] = df[['student_id', 'subject_name']].agg(frozenset, axis=1).map(s).fillna(0).astype(int)
    return df

# Solution 2 one liner
def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    return students.merge(subjects, how='cross').sort_values(by=['student_id', 'subject_name']).assign(attended_exams=lambda x: x[['student_id', 'subject_name']].agg(frozenset, axis=1).map(examinations[['student_id', 'subject_name']].agg(frozenset, axis=1).value_counts()).fillna(0).astype(int))
    
# Solution 3 one liner merge with left and right defined
def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=pd.merge(students, subjects, how='cross').sort_values(by=['student_id', 'subject_name']), right=examinations.groupby(['student_id', 'subject_name']).agg(attended_exams=('subject_name', 'count')).reset_index(), how='left', on=['student_id', 'subject_name'],).fillna(0)[['student_id', 'student_name', 'subject_name', 'attended_exams']]