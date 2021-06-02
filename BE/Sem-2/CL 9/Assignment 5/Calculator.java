package com.mycompany.soap_calculator;

import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.ejb.Stateless;

/**
 *
 * @author prachirishi
 */
@WebService(serviceName = "Calculator")
@Stateless()
public class Calculator {
int k;
    /**
     * This is a sample web service operation
     */
    @WebMethod (operationName="add")
    public int add(@WebParam(name="a")int a,@WebParam(name = "b")int b){
         k=a+b;
   return k;
}
        @WebMethod (operationName="subtract")
    public int subtract(@WebParam(name="a")int a,@WebParam(name = "b")int b){
        k=a-b;
   return k;
}
        @WebMethod (operationName="multiply")
    public int multiply(@WebParam(name="a")int a,@WebParam(name = "b")int b){
        k=a*b;
   return k;
}
        @WebMethod (operationName="divide")
    public int divide(@WebParam(name="a")int a,@WebParam(name = "b")int b){
        k=(a/b);
   return k;
}
}
