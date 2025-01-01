class Solution {
    public int maxScore(String s) {
        int leftZeros = 0, rightOnes = 0, maxScore = 0;
        int n = s.length();
        for (char c : s.toCharArray()) {
            if (c == '1')
                rightOnes++;
        }
        for(int i=0; i<n-1;i++){
            if(s.charAt(i) == '0')
                leftZeros++;
            if(s.charAt(i)=='1')
                rightOnes--;
            maxScore = Math.max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
    
}