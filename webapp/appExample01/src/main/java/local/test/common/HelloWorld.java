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
}
