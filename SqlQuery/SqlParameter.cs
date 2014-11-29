namespace common.core
{
    public class SqlParameter
    {
        public string _getName() {
            return mName;
        }

        public object _getValue() {
            return mValue;
        }

        public SqlParameter(string nName,
            object nValue) {
            mName = nName;
            mValue = nValue;
        }

        string mName;
        object mValue;
    }
}
