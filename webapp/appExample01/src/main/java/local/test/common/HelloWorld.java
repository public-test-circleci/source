package local.test.common;

/**
 * Hello world!
 *
 */
public class HelloWorld
{
	private String name;
	private String group;

	public void setName(String name) {
		this.name = Constant.PREFIX + name;
	}

	public void setGroup(String group) {
		this.group = Constant.PREFIX + group;
	}

	public void printHello() {
		System.out.println("Hello !! " + name + " of the" + group);
	}

	public void printPrefix() {
		System.out.println("confirm the prefix : " + Constant.PREFIX);
	}

	public void printHello1() {
		System.out.println("Hello1 ! " + name);
	}

	public void printHello2() {
		System.out.println("Hello2 ! " + name);
	}

	public void printHello3() {
		System.out.println("Hello3 ! " + name);
	}

	public void printHello4() {
		System.out.println("Hello4 ! " + name);
	}

	public void printHello5() {
		System.out.println("Hello5 ! " + name);
	}
}
