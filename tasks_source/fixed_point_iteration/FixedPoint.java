public class FixedPoint {

	double fixedPointCalculate(Function g,
				   double x0,
				   double tolerance,
				   int maxIterations) {
		// arbitrary 10 to make while loop run at least once
		double error = 10.0 * tolerance;
		double x1 = 0.0;
		int iterations = 0;

		while(error > tolerance && iterations < maxIterations) {
			x1 = g(x0);
			error = Math.abs(x1 - x0);
			x0 = x1;
			iterations++;
		}
		return x1;
	}

	public static void main(String[] args) {
		System.out.println("Hello");
	}
}
