/*
MySQL Data Transfer
Source Host: achilles.mcscw3.le.ac.uk
Source Database: yh37
Target Host: achilles.mcscw3.le.ac.uk
Target Database: yh37
Date: 29/09/2008 12:02:14
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for employee
-- ----------------------------
DROP TABLE IF EXISTS `employee`;
CREATE TABLE `employee` (
  `id` int(11) NOT NULL default '0',
  `firstname` varchar(255) default NULL,
  `lastname` varchar(255) default NULL,
  `address` varchar(255) default NULL,
  `salary` double default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `employee` VALUES ('1', 'David', 'Cameron', 'London', '900000');
INSERT INTO `employee` VALUES ('2', 'Clegg', 'Nick', 'Buckinghamshire', '800000');
