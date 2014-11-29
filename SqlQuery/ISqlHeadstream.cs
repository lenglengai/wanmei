namespace common.core
{
    public interface ISqlHeadstream
    {
        void _runSelect(ISqlCommand nSqlCommand);

        void _runWhere(ISqlCommand nSqlCommand);

        string _tableName();

        SqlType_ _sqlType();
    }
}
