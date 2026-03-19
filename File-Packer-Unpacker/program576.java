
import java.io.*;
import java.util.*;

class program576
{
    public static void main(String A[])throws Exception
    {
        int iRet=0;
        byte Buffer[]=new byte[100];
        boolean bRet=false;
        String FileName=null;
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the name of file :");

        FileName=sobj.nextLine();

        File fobj=new File(FileName);

        if(fobj.exists())
        {
            FileInputStream fiobj=new FileInputStream(fobj);
            String str=null;
            
            while((iRet=fiobj.read(Buffer))!=-1)
            {
                str=new String(Buffer,0,iRet);
                System.out.print(str);
                str=null;
            }
            System.out.println();
        }
        else
        {
            System.out.println("There is no such file");
        }
        
        sobj.close();
    }
}
        