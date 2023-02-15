-- 586. Customer Placing the Largest Number of Orders

SELECT customer_number FROM Orders GROUP BY customer_number HAVING COUNT(order_number)=(
SELECT MAX(orders) FROM (SELECT COUNT(order_number) orders FROM Orders GROUP BY customer_number) temp);