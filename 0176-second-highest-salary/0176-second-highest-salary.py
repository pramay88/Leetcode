import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    salary = employee['salary'].drop_duplicates().nlargest(2)
    if len(salary) < 2:
        return pd.DataFrame({'SecondHighestSalary' : [np.nan]})
    return pd.DataFrame({'SecondHighestSalary' : [salary.iloc[1]]})