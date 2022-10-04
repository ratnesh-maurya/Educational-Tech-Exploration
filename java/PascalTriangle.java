
public class PascalTriangle {
    public static List<List<Integer>> generate(final int numRows) {
        final List<List<Integer>> result = new ArrayList<>();
        List<Integer> currentRow = new ArrayList<>();
        currentRow.add(1);
        for (int i = 0; i < numRows; i++) {
            result.add(currentRow);
            currentRow = generateIt(currentRow);
        }

        return result;
    }

    private static List<Integer> generateIt(final List<Integer> currentRow) {
        final Integer[] thisRow = new Integer[currentRow.size() + 1];
        thisRow[0] = 1;
        for (int i = 0; i < currentRow.size() - 1; i++) {
            final int thisInt = currentRow.get(i) + currentRow.get(i + 1);
            thisRow[i + 1] = thisInt;
        }
        thisRow[currentRow.size()] = 1;
        return Arrays.asList(thisRow);

}
}