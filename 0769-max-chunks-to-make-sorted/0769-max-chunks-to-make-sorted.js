/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    let maxx = 0;
    let chunks = 0;
    for(let i=0; i<arr.length; i++){
        maxx = Math.max(arr[i],maxx);
        if(maxx == i){
            chunks++;
        } 
    }
    return chunks;
};