
import com.sun.jna.WString;
import com.sun.jna.*;
public class TestSo{
    public interface CLibrary extends Library {

        CLibrary INSTANCE = (CLibrary) Native.load("dosaic", CLibrary.class);
		void do_dosaic(WString file);
        //void listen(WString file);
        //void doNothing();
        //WString speak();
    }
    
    /*
        public static native void speak(WString file);
        public static native void doNothing();
        public static native WString listen();
        static{
            try{
                System.loadLibrary("dosaic");
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }	
        

    public void DoNothing(){
        CLibrary.INSTANCE.doNothing();
    } 
    public String Speak()
    {
        WString ws = CLibrary.INSTANCE.speak();
        return ws.toString();
    }
*/    
public void dosaic(String str)
    {
        WString ws = new WString(str);
        CLibrary.INSTANCE.do_dosaic(ws);
    }
}