package local.test.common;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Hello world!
 *
 */
public class App
{
    public static void main( String[] args )
    {
    	ApplicationContext context = new ClassPathXmlApplicationContext("Spring-Module.xml");

        HelloWorld obj = (HelloWorld) context.getBean("helloBean");
        obj.printPrefix();
        obj.printHello();

        HelloWorld1 obj1 = (HelloWorld1) context.getBean("helloBean1");
        obj1.printHello1();

        HelloWorld2 obj2 = (HelloWorld2) context.getBean("helloBean2");
        obj2.printHello2();

        HelloWorld3 obj3 = (HelloWorld3) context.getBean("helloBean3");
        obj3.printHello3();

        HelloWorld4 obj4 = (HelloWorld4) context.getBean("helloBean4");
        obj4.printHello4();

        HelloWorld5 obj5 = (HelloWorld5) context.getBean("helloBean5");
        obj5.printHello5();

    }
}
