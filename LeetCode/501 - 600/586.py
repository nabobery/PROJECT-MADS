# 586. Customer Placing the Largest Number of Orders
import pandas as pd

# Solution 1 using mode function
def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(orders.customer_number.mode(), columns= ['customer_number'])

# Solution 2 using value_counts function
def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(orders.customer_number.value_counts().head(1).index, columns= ['customer_number'])
    
# Solution 3 using groupby function
def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(orders.groupby('customer_number').size().sort_values(ascending=False).head(1).index, columns= ['customer_number'])
