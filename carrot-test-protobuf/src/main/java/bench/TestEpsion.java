package bench;

public class TestEpsion {

	public static void main(final String... args) {

		calculateEpsilonFloat();

		calculateEpsilonDouble();

	}

	static void calculateEpsilonFloat() {

		float machEps = 1.0f;

		do {

			machEps /= 2.0f;

		} while ((1.0f + (machEps / 2.0f)) != 1.0f);

		System.out.println("epsilon/float : " + machEps);

	}

	static void calculateEpsilonDouble() {

		double machEps = 1.0d;

		do {

			machEps /= 2.0d;

		} while ((1.0d + (machEps / 2.0d)) != 1.0d);

		System.out.println("epsilon/double : " + machEps);

	}

}
