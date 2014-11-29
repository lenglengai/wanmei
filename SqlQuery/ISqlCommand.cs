using System.Collections.Generic;

namespace common.core
{
    public interface ISqlCommand
    {
        void _serialize(ref bool nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);

        void _serialize(ref sbyte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<sbyte> nValue, string nName);

        void _serialize(ref byte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<byte> nValue, string nName);

        void _serialize(ref byte[] nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);

        void _serialize(ref short nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<short> nValue, string nName);

        void _serialize(ref ushort nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<ushort> nValue, string nName);

        void _serialize(ref int nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<int> nValue, string nName);

        void _serialize(ref uint nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<uint> nValue, string nName);

        void _serialize(ref long nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<long> nValue, string nName);

        void _serialize(ref ulong nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<ulong> nValue, string nName);

        void _serialize(ref string nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<string> nValue, string nName);

        void _serialize(ref float nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<float> nValue, string nName);

        void _serialize(ref double nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize(ref List<double> nValue, string nName);

        void _serialize<__t>(ref __t nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void _serialize<__t>(ref List<__t> nValue, string nName)
            where __t : ISqlStream;
    }
}
