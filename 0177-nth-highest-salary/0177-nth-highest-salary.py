import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    salary = employee['salary'].drop_duplicates().nlargest(N)
    col_name = f'getNthHighestSalary({N})'
    if N <= 0:
        return pd.DataFrame({col_name: [None]})
    if len(salary) < N:
        return pd.DataFrame({col_name: [None]})
    return pd.DataFrame({col_name : [salary.iloc[N-1]]})