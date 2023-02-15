-- 607. Sales Person

SELECT name FROM SalesPerson WHERE sales_id NOT IN (SELECT sales_id FROM ORDERS INNER JOIN Company ON Orders.com_id = Company.com_id WHERE Company.name = "RED");

