using System;
using System.Collections.Generic;
using MySql.Data.MySqlClient;

namespace common.core
{
    public class SqlReader : ISqlCommand
    {
        public void _serialize(ref bool nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetBoolean(nName);
        }

        public void _serialize(ref sbyte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetSByte(nName);
        }

        public void _serialize(ref List<sbyte> nValue, string nName) {
        }

        public void _serialize(ref byte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetByte(nName);
        }

        public void _serialize(ref List<byte> nValue, string nName) {

        }

        public void _serialize(ref byte[] nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            string name = string.Format(@"{0}_i", nName);
            int size_ = mMySqlDataReader.GetInt32(name);
            nValue = new byte[size_];
            int ordinal = mMySqlDataReader.GetOrdinal(nName);
            mMySqlDataReader.GetBytes(ordinal, 0, nValue, 0, size_);
        }

        public void _serialize(ref short nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetInt16(nName);
        }

        public void _serialize(ref List<short> nValue, string nName) {
        }

        public void _serialize(ref ushort nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetUInt16(nName);
        }

        public void _serialize(ref List<ushort> nValue, string nName) {

        }

        public void _serialize(ref int nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetInt32(nName);
        }

        public void _serialize(ref List<int> nValue, string nName) {

        }

        public void _serialize(ref uint nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetUInt32(nName);
        }

        public void _serialize(ref List<uint> nValue, string nName) {
        }

        public void _serialize(ref long nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetInt64(nName);
        }

        public void _serialize(ref List<long> nValue, string nName) {
        }

        public void _serialize(ref ulong nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetUInt64(nName);
        }

        public void _serialize(ref List<ulong> nValue, string nName) {

        }

        public void _serialize(ref string nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetString(nName);
        }

        public void _serialize(ref List<string> nValue, string nName) {

        }

        public void _serialize(ref float nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetFloat(nName);
        }

        public void _serialize(ref List<float> nValue, string nName) {

        }

        public void _serialize(ref double nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            nValue = mMySqlDataReader.GetDouble(nName);
        }

        public void _serialize(ref List<double> nValue, string nName) {

        }

        public void _serialize<__t>(ref __t nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
        }

        public void _serialize<__t>(ref List<__t> nValue, string nName)
            where __t : ISqlStream {
            __t t_ = Activator.CreateInstance<__t>();
            t_._runSelect(this);
            nValue.Add(t_);
        }

        public bool _runRead() {
            return mMySqlDataReader.Read();
        }

        public void _runClose() {
            mMySqlDataReader.Close();
        }

        public SqlReader(MySqlDataReader nMySqlDataReader) {
            mMySqlDataReader = nMySqlDataReader;
        }

        MySqlDataReader mMySqlDataReader;
    }
}
