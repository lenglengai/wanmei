/**
 *		作用：		设置数据库密码
 */
SET old_passwords=FALSE;
SET PASSWORD = PASSWORD('zyouhua');
/**
 *		作用：		创建数据库
 * 		数据库名：	weibo
 */
CREATE DATABASE wanmei;
USE wanmei;
/**
 *		作用：		创建account表
 * 		表名：		account
 *		表的数量：	tableCount
 */
DELIMITER $$

DROP PROCEDURE IF EXISTS `account`$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `account`()
BEGIN
	DECLARE i INT DEFAULT 0;
	DECLARE tableCount INT DEFAULT 20;
	WHILE i < tableCount
	DO
		SET @STMT := CONCAT("CREATE  TABLE `account_", FORMAT(i, 0), "` (
					`accountId` INT(10) UNSIGNED NOT NULL ,
					`applicationId` INT(10) UNSIGNED NOT NULL ,
					`accountName` VARCHAR(45) NOT NULL ,
					`nickName` VARCHAR(45) NOT NULL ,
					`passward` VARCHAR(45) NOT NULL ,
					`getPassward` VARCHAR(45) NOT NULL ,
					`createTime` BIGINT NOT NULL ,
					`clusterID` INT(10) UNSIGNED NOT NULL ,
					`serverID` INT(10) UNSIGNED NOT NULL ,
					`databaseId` INT(10) UNSIGNED NOT NULL ,
					`tableId` INT(10) UNSIGNED NOT NULL ,
					PRIMARY KEY (`accountId`) )
					ENGINE = MYISAM  DEFAULT CHARSET=utf8;");
		PREPARE STMT FROM @STMT;
		EXECUTE STMT;
		SET i = i + 1;
	END WHILE;
END$$

DELIMITER ;

CALL `account`();

DROP PROCEDURE IF EXISTS `account`;
