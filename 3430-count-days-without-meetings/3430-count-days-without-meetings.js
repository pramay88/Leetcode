/**
 * @param {number} days
 * @param {number[][]} meetings
 * @return {number}
 */
var countDays = function(days, meetings) {
    meetings.sort((a, b) => a[0] - b[0]);
    let covered = 0, prevEnd = -1;

    for (let m of meetings) {
        let start = Math.max(prevEnd + 1, m[0]);
        if (start <= m[1]) {  
            covered += (m[1] - start + 1);
            prevEnd = Math.max(prevEnd, m[1]);
        }
    }

    return days - covered;
};