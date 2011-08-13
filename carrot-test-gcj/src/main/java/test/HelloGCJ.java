package test;

public class HelloGCJ {

	static final int COUNT = 10 * 1000 * 1000;

	public static void main(String[] args) {

		System.out.println("init"); //
		long init = System.nanoTime();

		double[] array = new double[COUNT];
		
		for (int k = 0; k < COUNT; k++) {
				array[k] = Math.log(k);
		}

		long done = System.nanoTime();
		System.out.println("done"); //

		long diff = done - init;

		System.out.println("nano=" + (diff / COUNT)); //

	}

}
