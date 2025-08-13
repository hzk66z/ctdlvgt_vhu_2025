package com.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class NewClass {
    public static void main(String[] args){
        //TODO Auto-generated method stub
        
        //JDBC URL ket noi voi SQL Sever
        String url = "jdbc:sqlserver://localhost:1433;databaseName = YourDB;encrypt=true;trustServerCertificate=true";
        String user = "sa"; //Tai khoan dang nhap SQL Server
        String password = "your_secure_password"; //Mat khau
        
        try{
            //Ket noi den SQL Server
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Ket noi thanh cong den SQL Server!");
            
            //Dong ket noi sau khi hoan tat
            conn.close();
        } catch(SQLException e){
            System.err.println("Loi ket noi: " + e.getMessage());
        }
    }
}