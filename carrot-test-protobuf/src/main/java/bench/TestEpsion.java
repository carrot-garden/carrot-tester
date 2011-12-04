package bench;

public class TestEpsion {

	public static void main(String... args) {

		calculateMachineEpsilonFloat();

	}

	static void calculateMachineEpsilonFloat() {

		float machEps = 1.0f;

		do {

			machEps /= 2.0f;

			System.out.println("Calculated machine epsilon: " + machEps);

		} while ((float) (1.0 + (machEps / 2.0)) != 1.0);

		System.out.println("Calculated machine epsilon: " + machEps);

	}

}
