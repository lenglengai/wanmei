using System.Collections.Generic;
using MySql.Data.MySqlClient;

namespace common.core
{
    public class SqlService : IHeadstream
    {
        public void _headSerialize(ISerialize nSerialize) {
            nSerialize._serialize(ref mConnectionString,
                @"connectionString");
        }

        public string _streamName() {
            return @"sqlService";
        }

        public __tuple<int, string> _runSqlCommand(SqlCommand nSqlCommand) {
            int errorCode = 0; string errorMessage = null;
            MySqlConnection mySqlConnection_ = new MySqlConnection(mConnectionString);
            try {
                mySqlConnection_.Open();
                MySqlCommand mySqlCommand_ = new MySqlCommand();
                mySqlCommand_.Connection = mySqlConnection_;
                string sqlCommand_ = nSqlCommand._sqlCommand();
                mySqlCommand_.CommandText = sqlCommand_;
                IList<SqlParameter> fields_ = nSqlCommand._getFields();
                foreach (SqlParameter i in fields_) {
                    mySqlCommand_.Parameters.AddWithValue(i._getName(), i._getValue());
                }
                mySqlCommand_.ExecuteNonQuery();
            } catch (MySqlException exception_) {
                errorCode = exception_.Number;
                errorMessage = exception_.Message;
            }
            mySqlConnection_.Close();
            return new __tuple<int, string>(errorCode, errorMessage);
        }

        public bool _runSqlCommand(SqlCommand nSqlCommand,
            ISqlHeadstream nSqlHeadstream) {
            bool result = true;
            MySqlConnection mySqlConnection_ =
                new MySqlConnection(mConnectionString);
            try {
                mySqlConnection_.Open();
                string sqlCommand_ = nSqlCommand._sqlCommand();
                MySqlCommand mySqlCommand_ =
                    new MySqlCommand(sqlCommand_, mySqlConnection_);
                MySqlDataReader mySqlDataReader_ =
                    mySqlCommand_.ExecuteReader();
                SqlReader sqlReader_ =
                    new SqlReader(mySqlDataReader_);
                while (sqlReader_._runRead()) {
                    nSqlHeadstream._runSelect(sqlReader_);
                }
                sqlReader_._runClose();
            } catch (MySqlException exception_) {
                LogService logService_ = 
                    __singleton<LogService>._instance();
                string logError = 
                    string.Format(@"sqlError:{0},{1}", 
                    exception_.Number,
                    exception_.Message);
                logService_._logError(logError);
                result = false;
            }
            mySqlConnection_.Close();
            return result;
        }

        public void _runPreinit() {
            this._initConfig();
        }

        void _initConfig() {
            string sqlUrl_ = @"Config/sql.xml";
            XmlReader xmlReader_ = new XmlReader();
            xmlReader_._openUrl(sqlUrl_);
            xmlReader_._selectStream(_streamName());
            this._headSerialize(xmlReader_);
            xmlReader_._runClose();
        }

        public SqlService() {
            mConnectionString = null;
        }

        string mConnectionString;
    }
}
