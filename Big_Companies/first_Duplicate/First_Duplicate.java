package first_Duplicate;

public class First_Duplicate {
    // Áp dụng cho Đề bài cho mảng chỉ chứa các phần tử 
    //trong đoạn [1, arr.length]
    public int firstDuplicate(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[Math.abs(arr[i]) - 1] < 0) return Math.abs(arr[i]);
            arr[Math.abs(arr[i]) - 1] = -arr[Math.abs(arr[i]) - 1];
        }
        return -1;
    }
    
    public static void main(String[] args) {
        First_Duplicate f = new First_Duplicate();
        int[] arr = {2, 1, 3, 5, 3, 2};
        System.out.println(f.firstDuplicate(arr));
    }
}
