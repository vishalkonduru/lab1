public class StudentResult { 
 
    /** 
     * Computes the student's result string based on marks and attendance. 
     * 
     * Decision logic: 
     * 1) invalid marks? -> "Invalid" 
     * 2) marks < 40 -> "Fail" 
     * 3) 40 <= marks < 60 -> depends on attendance: 
     *      - attended -> "Pass" 
     *      - not attended -> "Fail (attendance)" 
     * 4) 60 <= marks < 80 -> "Merit" 
     * 5) marks >= 80 -> "Distinction" 
     */ 
    public static String computeResult(int marks, boolean attended) { 
        // Decision 1: invalid input 
        if (marks < 0 || marks > 100) { 
            return "Invalid"; 
        } 
 
        // Decision 2: fail if < 40 
        if (marks < 40) { 
            return "Fail"; 
        } 
 
        // Decision 3: pass region 40-59 (attendance matters) 
        if (marks < 60) { 
            if (attended) { 
                return "Pass"; 
            } else { 
                return "Fail (attendance)"; 
            } 
        } 
 
        // Decision 4: merit 60-79 
        if (marks < 80) { 
            return "Merit"; 
        } 
 
        // Decision 5: >= 80 
        return "Distinction"; 
    } 
 
    // simple manual-run demo 
    public static void main(String[] args) { 
        int[] testMarks = {-1, 30, 55, 55, 70, 85}; 
        boolean[] testAttendance = {true, true, true, false, true, true}; 
 
        for (int i = 0; i < testMarks.length; i++) { 
System.out.printf("marks=%d attended=%b -> %s%n", testMarks[i], testAttendance[i], 
computeResult(testMarks[i], testAttendance[i])); 
} 
} 
} 